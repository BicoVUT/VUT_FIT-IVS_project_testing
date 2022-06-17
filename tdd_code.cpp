//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Filip Brna <xbrnaf00@stud.fit.vutbr.cz>
// $Date:       $2021-02-28
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Filip Brna
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    m_pHead = NULL;
}

PriorityQueue::~PriorityQueue()
{
	m_pHead = NULL;
}

void PriorityQueue::Insert(int value)
{

    auto prev_to_insert = new Element_t; //previous one of inserted element
    auto to_insert = new Element_t; //inserted element
	auto current = new Element_t; //current element
	to_insert->value = value;  //set value  of element which we need to insert
    current = GetHead();
    bool changed = false;

	//insert on first position because queue is empty
	if(current == NULL){
		m_pHead = to_insert;
		to_insert->pNext = NULL;
		to_insert->value = value;
        delete current;
        delete prev_to_insert;
	}
	else{
		//insert on first position
		if(current->value <= to_insert->value){
                        to_insert->pNext = current;
                        to_insert->value = value;
			            m_pHead = to_insert;
                        changed = true;
                        delete prev_to_insert;
		}

		//insert in correct position
		while( current != NULL && changed == false){
			if(current->value <= to_insert->value){
                prev_to_insert->pNext = to_insert;
                to_insert->pNext = current;
                to_insert->value = value;
				changed = true;
			}
			if( changed == false ){
                prev_to_insert = current;
				current = current->pNext;
			}
		}
		
		//insert at the end
		if(current == NULL && changed == false){
            prev_to_insert->pNext = to_insert;
			to_insert->pNext = NULL;
            delete current;
		}
	}
}

bool PriorityQueue::Remove(int value)
{

    auto prev_to_remove = new Element_t; //previous one of removed element
    auto to_remove = new Element_t; //removed element
    to_remove = GetHead();
    
    //if queue is empty 
    if ( to_remove == NULL){  
        delete prev_to_remove;
        delete to_remove;  
        return false;
    }

    //remove from first position 
    if(to_remove->value == value){
        m_pHead = to_remove->pNext;
		delete to_remove;
        delete prev_to_remove;
		return true;
	}


	//remove correct element or false 
	while(to_remove != NULL){
		if(to_remove->value == value){
            prev_to_remove->pNext = to_remove->pNext;
			delete to_remove;
			return true;
		}
        if(to_remove->pNext != NULL){
            prev_to_remove = to_remove;
            to_remove = to_remove->pNext;
		}
        else{
            to_remove = to_remove->pNext;
        }
	}
    return false;
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{

    auto current = new Element_t; //element to compare with value
	current = GetHead();
    
    //goes element by element and compare values,
    //if there is match return pointer of element
    while( current != NULL) {
        if ( current->value == value ){
            return current;
        }
        current = current->pNext;
    }

    delete current;
    return NULL; 
}

size_t PriorityQueue::Length()
{
    auto object = new Element_t;
	object = GetHead();
    int counter = 0;

    //counter
    while( object != NULL ){
        counter++;
        object = object->pNext; 
    }
    delete object;
    return counter;

}


PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    //return actual Head
    return m_pHead;
}