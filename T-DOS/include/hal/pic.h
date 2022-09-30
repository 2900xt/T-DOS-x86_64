#pragma once
void pic_Remap(int offseta, int offsetb);
void sendEOI(uint8_t irq);
void enableIRQ(uint8_t IRQ);
void maskIRQ(uint8_t IRQ);
