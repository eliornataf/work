/*****************************************************************************
* File Name: Container Utilites
* Written by: Elior Nataf
* Date: 23/5/21
******************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __CONTAINER_UTILITES_HPP__
#define __CONTAINER_UTILITES_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <deque> /* std::deque */
#include <list> /* std::list */
#include "entry.hpp" /* Entry Header */

/*---------------------------------- Typedef ---------------------------------*/

typedef Entry entryType;
typedef std::list<entryType> innerContainer;
typedef std::deque<innerContainer> outerContainer;

/*----------------------------------------------------------------------------*/

#endif /* __CONTAINER_UTILITES_HPP__ */
