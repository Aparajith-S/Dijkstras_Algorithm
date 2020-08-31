/// @file:
/// @author:
/// @date :
/// @brief : workaround for template class definitions.


#pragma once
#include<vector>
#include"myalgorithm.h"
typedef unsigned int uint32;

/// @class Priority queue based on min heap
/// @brief Priority queue which accepts a pair <prio,name> where name is a type could be an integer,string etc. but prio is always float
template<class Type>
class PriorityQueue
{
public:

	///@brief constructor constructs an empty priority Queue
	PriorityQueue() :PQ() {};
	
	///@brief clean default user defined destructor
	virtual ~PriorityQueue() {};

	///@brief Change the priority of the given node
	///@details node priority is changed by removing the old node priority in O(N) and inserting new node priority in O(logN) 
	///@param[in] nodeName: node name whose priority has to be changed
	///@param[in] prio: priority of the node 
	///@return true when node is found
	///@return false when node is not found
	bool chgPriority(const Type& nodeName, const float prio);
	
	///@brief removes the top most element whose priority is minimum
	///@details this is a min heap implementation.
	///         hence, the elements are ordered in ascending order of priority in the queue. this function pops that element
	///@return true if there is an element in the prio queue that can be popped
	///@return false if the prio queue itself is empty
	bool minPriority();

	///@brief if the said node is available in the priority queue
	///@details finds an available node in linear (O(N)) time
	///@param[in] nodeName name of the to-be-found node
	///@return true if the element exists
	///@return false if the element does not exist
	bool contains(const Type& nodeName);

	///@brief inserts a new node into the priority queue
	///@details inserts a new element in the queue in O(logN) time 
	///@param[in] nodeName : the vertex Name to be inserted
	///@param[in] prio : the priority of the element
	///@return true if the operation was successful
	///@return false if the operation was not successful
	bool insertQ(const Type& nodeName,const float prio);
	 
	///@brief top returns the top element in the priority queue
	///@details Constant time operation. 
	///@return true if the operation is successful and the element in the queue.
	std::pair<bool, std::pair<float,Type>> top();
	
	///@brief returns the size of the Priority queue
	///@return unsigned integer size 
	size_t size();

private:
	
	///@brief container to hold the queue in a pair and sorted by first value 
	std::vector<std::pair<float,Type>> PQ;
};

// C++ compilers have a problem with template classes being seperated into declarations in .h and definitions in .cpp files. 
// Hence, this will still keep code clean and circumvent the compiler problem. 
// caveat: to be used only in small projects. 

template<class Type>
bool PriorityQueue<Type>::chgPriority(const Type& Value, const float prio)
{
	float oldPrio;
	bool found = false;
	for (auto iter = PQ.begin();
		iter != PQ.end();
		iter++)
	{
		if (iter->second == Value)
		{
			oldPrio = iter->first;
			found = true;
			break;
		}
	}

	if (found)
	{
		PQ.erase(oldPrio);
		PQ.insert(std::pair<float, Type>(prio, Value));
	}
	return found;
}

template<class Type>
bool PriorityQueue<Type>::minPriority()
{
	bool success = false;
	if (PQ.size())
	{
		PQ.pop_back();
		success = true;
	}
	return success;
}

template<class Type>
bool PriorityQueue<Type>::contains(const Type& Value)
{
	uint32 dummy = 0;
	bool found = false;
	for (auto iter = PQ.begin();
		iter != PQ.end();
		iter++)
	{
		if (iter->second == Value)
		{
			found = true;
			break;
		}
	}
	return found;
}

template<class Type>
bool PriorityQueue<Type>::insertQ(const Type& nodeValue, const float prio)
{
	if (PQ.size())
	{
		auto pos = binary_search(PQ.begin(),
			PQ.end(),
			std::pair<float,Type>(prio,nodeValue),
			[&]( std::pair<float, Type> left,  std::pair<float, Type> right) {return (left.first < right.first);});
		
		static_cast<void>(PQ.insert(pos, std::pair<float, Type>(prio, nodeValue)));
	}
	else
	{
		PQ.push_back(std::pair<float, Type>(prio, nodeValue));
	}

	return true;
}

template<class Type>
std::pair<bool, std::pair<float, Type>> PriorityQueue<Type>::top()
{
	std::pair<bool, std::pair<float, Type>> returnVal;
	returnVal.first = false;
	if (PQ.size())
	{
		returnVal.second.second = PQ[PQ.size() - 1].second;
		returnVal.second.first = PQ[PQ.size()-1].first;

		returnVal.first = true;
	}
	return returnVal;
}

template<class Type>
size_t PriorityQueue<Type>::size()
{
	return PQ.size();
}
