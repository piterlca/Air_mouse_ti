/*
 * ring_buffer.h
 *
 *  Created on: 10 paŸ 2015
 *      Author: Domowy
 */

#ifndef I2C_RING_BUFFER_H_
#define I2C_RING_BUFFER_H_

#define RING_BUFFER_SIZE_t uint8_t

typedef struct ring_buffer
{
	volatile void**		head;
	void**				begin_ptr;
	void**				end_ptr;
}ring_buffer;

ring_buffer* init_ring_buffer(RING_BUFFER_SIZE_t buffer_size_in_elements, size_t size_of_element_b);

inline void add_element_to_buffer(ring_buffer* rng_buf, void* element)
{
	(	*(rng_buf->head++)	) = element;

	if(rng_buf->head >= rng_buf->end_ptr)
		rng_buf->head = rng_buf->begin_ptr;
}

inline void* read_element_from_buffer(ring_buffer* rng_buf)
{
	void* element_ptr = (	*(--rng_buf->head)	);

	if(rng_buf->head <= rng_buf->begin_ptr)
		rng_buf->head = rng_buf->end_ptr - 1;

	return element_ptr;
}

void destroy_ring_buffer(ring_buffer* rng_buf);

#endif /* I2C_RING_BUFFER_H_ */
