/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.

*/

#include "split.h"
#include <cstddef>
#include <iostream>
/* A dd a prototype for a helper function here if you need */



void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in-> next == nullptr)
  {
    // if(in-> value == NULL)
    return;
  }

  else if (in -> next != nullptr && in-> value % 2 == 0)
  {
    if (evens == nullptr)
    {
      std::cout << "testing first item in evens" << std::endl;
      evens = in;
      std::cout << "first item evens" << " " <<evens-> value << " " << in-> value << std::endl;
      split(in-> next, odds, evens);
    }
    else 
    {
    std::cout << "testing not not not first item in evens" << std::endl;
    evens-> next = in;
    std::cout << "not first evens " << " " <<evens-> value << " " << in-> value << std::endl;
    split(in-> next, odds, evens->next);
    }

  }
  else if (in -> next != nullptr && in -> value % 2 != 0)
  {
    if (odds == nullptr)
    {
      std::cout << "testing first item in odds" << std::endl;
      odds = in;
      std::cout << "first item odds" << " " <<odds-> value << " " << in-> value << std::endl;
      split(in-> next, odds, evens);
    }
    else 
    {
      std::cout << "testing not not not first item in odds" << std::endl;
      odds->next = in;
      std::cout << "not first odds" << " " << odds-> value << " " << in -> value<< std::endl;
    split(in-> next, odds->next, evens);

    }
  }

  else 
  {
    in = NULL;

    return;

  }

}



// /* If you needed a helper function, write it here */



/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.

*/

#include "split.h"
#include <cstddef>
#include <iostream>
/* A dd a prototype for a helper function here if you need */



void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr)
  {
    if (odds != nullptr)
    {
          odds-> next = NULL;
    }
     if (evens != nullptr)
    {
          evens-> next = NULL;
    }
    return;
  }

  else if (in-> value % 2 == 0)
  {
    if (evens == nullptr)
    {
      evens = in;
      in = in -> next;
      split(in, odds, evens); 
    }
    else 
    {
      evens-> next = in;
      in = in-> next;
      split(in, odds, evens->next);
    }

  }
  else if ( in -> value % 2 != 0)
  {
    if (odds == nullptr)
    {
      odds = in;
      in = in-> next;
      split(in, odds, evens); 
    }
    else 
    {
      odds->next = in;
      in = in-> next;
      split(in, odds->next, evens);
    }

  }
   in = NULL;


}
