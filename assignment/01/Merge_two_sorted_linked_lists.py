#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node


        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)

# Complete the mergeLists function below.

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

# alternative1
def mergeLists(head1, head2):
    dummy = SinglyLinkedListNode(None)
    head = dummy

    while head1 and head2:
        if head1.data > head2.data:
            head1, head2 = head2, head1
        
        head.next = head1
        head1 = head1.next
        head = head.next
    
    if head1 != None:
        head.next = head1
    else:
        head.next = head2

    
    return dummy.next

# alternative 2
def mergeLists(head1, head2):
    if head1 is None:
        return head2
    if head2 is None:
        return head1

    if head1.data <= head2.data:
        head = head1
        curr1 = head1.next
        curr2 = head2
    else:
        head = head2
        curr1 = head1
        curr2 = head2.next

    curr = head
        
    while True:
        if curr1 is None:
            curr.next = curr2
            break
        elif curr2 is None:
            curr.next = curr1
            break

        if curr1.data <= curr2.data:
            curr.next = curr1
            curr1 = curr1.next
        else:
            curr.next = curr2
            curr2 = curr2.next
        
        curr = curr.next

    return head
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    tests = int(input())

    for tests_itr in range(tests):
        llist1_count = int(input())

        llist1 = SinglyLinkedList()

        for _ in range(llist1_count):
            llist1_item = int(input())
            llist1.insert_node(llist1_item)
            
        llist2_count = int(input())

        llist2 = SinglyLinkedList()

        for _ in range(llist2_count):
            llist2_item = int(input())
            llist2.insert_node(llist2_item)

        llist3 = mergeLists(llist1.head, llist2.head)

        print_singly_linked_list(llist3, ' ', fptr)
        fptr.write('\n')

    fptr.close()
