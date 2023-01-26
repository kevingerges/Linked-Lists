/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>


int main(int argc, char* argv[])
{
    Node* odd = nullptr;
    Node* even= nullptr;


    Node* head = new Node(1, nullptr);
    Node* head1 = new Node(2,nullptr);
    Node* head2 = new Node(3, nullptr);
    Node* head3 = new Node(4,nullptr);
    Node* head4 = new Node(5, nullptr);
    Node* head5 = new Node(6,nullptr);

    head-> next = head1;
    head1-> next = head2;
    head2-> next = head3;
    head4-> next = head5;
    head5-> next = nullptr;

    split(head,odd,even);
    std::cout << "my list" << std::endl;
    std::cout << "even numbers" <<  even->value << std::endl;
    std::cout << "odd numbers"<< odd->value << std::endl;
    

}

