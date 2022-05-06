// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
        if (first != nullptr && last != nullptr) {
            last->next = create(light);
            last->next->prev = last;
            last = last->next;
            last->next = first;
            first->prev = last;
        } else {
            first = last = create(light);
        }
    }; 
    int Train::getLength() {
        first->light = true;
        while (first->next != nullptr) {
            if (first->next->light != true) {
                countOp++;
                k++;
                first->next = first->next->next;
            }
            else {
                if (first->next->light) {
                    first->next->light = false;
                    countOp++;
                }
                for (int i = k; i > 0; i--) {
                    first->next = first->next->prev;
                    countOp++;
                }
                if (first->next->light!=true) {
                    break;
                }
                first->next = first->next->next;
                k = 1;
            }
        }
        return k;
    }
    int Train::getOpCount() {
        return countOp;
    }
