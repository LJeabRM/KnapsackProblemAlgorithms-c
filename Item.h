#ifndef ITEM_H
#define ITEM_H

// Structure for items
typedef struct {
    int weight;  // น้ำหนักของสินค้า
    int value;   // มูลค่าของสินค้า
    int isPick;  // สถานะการเลือก (0 = ไม่เลือก, 1 = เลือก)
} Item;

#endif
