// alternative provided by TA 鄧晉杰
SinglyLinkedListNode* mergeLists (SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
  SinglyLinkedList merged_list;
  SinglyLinkedListNode *current_node1 {head1};
  SinglyLinkedListNode *current_node2 {head2};
  while ((current_node1 != nullptr) && (current_node2 != nullptr))
  {
    if (current_node1->data < current_node2->data)
    {
      merged_list.insert_node(current_node1->data);
      current_node1 = current_node1->next;
    }
    else
    {
      merged_list.insert_node(current_node2->data);
      current_node2 = current_node2->next;
    }
  }
  while (current_node1 != nullptr)
  {
    merged_list.insert_node(current_node1->data);
    current_node1 = current_node1->next;
  }
  while (current_node2 != nullptr)
  {
    merged_list.insert_node(current_node2->data);
    current_node2 = current_node2->next;
  }
  return merged_list.head;
}

// alternative provided by TA 李旺陽
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *res = nullptr;
    SinglyLinkedListNode **next = &res;

    while ( head1 && head2 ) {
        if (head1->data > head2->data)
            swap(head1, head2);
        *next = head1;
        head1 = head1->next;
        next = &(*next)->next;
    }
    if (head1) *next = head1;
    else *next = head2;

    return res;
}
