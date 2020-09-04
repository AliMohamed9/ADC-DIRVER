/*
 * seven_segments.h
 *
 *  Created on: Jul 18, 2020
 *      Author: MeGa
 */

#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_

#include<avr/io.h>
#include<util/delay.h>



void seven_segment_init(void);
void display_4_Digits_7Segment(unsigned int number);


#endif /* SEVEN_SEGMENTS_H_ */
