/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
   // 
   // Construct
   //
   BNode()
   : pLeft(nullptr),
   pRight(nullptr),
   pParent(nullptr),
   data{}  // value-initialize (e.g., 0 for ints)
   {}
   BNode(const T& t)
   : pLeft(nullptr),
   pRight(nullptr),
   pParent(nullptr),
   data(t) // copy
   {}
   BNode(T&& t)
   : pLeft(nullptr),
   pRight(nullptr),
   pParent(nullptr),
   data(std::move(t)) // move
   {}

   //
   // Data
   //
   BNode <T>* pLeft;
   BNode <T>* pRight;
   BNode <T>* pParent;
   T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode <T> * p)
{
   if (!p) // return early if non existent
      return 0;
   //recursively return through each node to get the size
   return 1 + size(p->pLeft) + size(p->pRight);
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   pNode->pLeft = pAdd; //assign new node to the left side

   if (pAdd)
      pAdd->pParent = pNode; //hook the new node up to the parent
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight(BNode <T> * pNode, BNode <T> * pAdd)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   pNode->pRight = pAdd; //assign new node to the left side

   if (pAdd)
      pAdd->pParent = pNode; //hook the new node up to the parent
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T>* pNode, const T& t)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   BNode<T>* pAdd = new BNode<T>(t); //create new node
   addLeft(pNode, pAdd); // add it in using addLeft()
}

template <class T>
inline void addLeft(BNode <T>* pNode, T&& t)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   BNode<T>* pAdd = new BNode<T>(std::move(t)); // create new node
   addLeft(pNode, pAdd); // Add it in using the addLeft method
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight(BNode <T>* pNode, const T& t)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   BNode<T>* pAdd = new BNode<T>(t); // make a new node
   addRight(pNode, pAdd); // use addRight to add the node to the right
}

template <class T>
void addRight(BNode <T>* pNode, T&& t)
{
   if (pNode == nullptr) // return early if nonexistent
      return;

   BNode<T>* pAdd = new BNode<T>(std::move(t)); // make a new node
   addRight(pNode, pAdd); // use add right to add it in
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{

}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{

}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
   return new BNode<T>;
}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode <T> * & pDest, const BNode <T>* pSrc)
{

}
