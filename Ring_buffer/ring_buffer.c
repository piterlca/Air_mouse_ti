/*
 * ring_buffer.c
 *
 *  Created on: 10 paü 2015
 *      Author: Domowy
 */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../generalDefs.h"
#include "ring_buffer.h"

#define RNGBUF_BOOL uint8_t

ring_buffer* init_ring_buffer(RING_BUFFER_SIZE_t buffer_size_in_elements, size_t size_of_element_b)
{
	ring_buffer* rng_buffer = (ring_buffer*)malloc(sizeof(ring_buffer));

	rng_buffer->head = rng_buffer->begin_ptr = malloc(sizeof(void*) * buffer_size_in_elements);
	if(NULL == rng_buffer)	return NULL;

	memset(rng_buffer->begin_ptr, 0, sizeof(void*) * buffer_size_in_elements );

	while(buffer_size_in_elements--)
	{
		rng_buffer->head = malloc(size_of_element_b);
		memset(rng_buffer->head, 0, size_of_element_b);
		++rng_buffer->head;
	}

	rng_buffer->head = rng_buffer->begin_ptr;

	return rng_buffer;
}

void destroy_ring_buffer(ring_buffer* rng_buf)
{
	free(rng_buf->begin_ptr);

	free(rng_buf);
}
