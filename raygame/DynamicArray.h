#pragma once
#include <exception>

template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray() {};

	/// <summary>
	/// Adds an item to the end of the array
	/// </summary>
	/// <param name="item">The new item to add to the array</param>
	void addItem(T item);

	/// <summary>
	/// Removes the item from the array
	/// </summary>
	/// <param name="actor">The item to remove</param>
	/// <returns>False if the item is not in the array</returns>
	bool removeItem(T item);

	/// <summary>
	/// Removes the item from the array
	/// </summary>
	/// <param name="actor">The item to remove</param>
	/// <returns>False if the item is not in the array</returns>
	bool removeItem(int index);

	void sortItems();

	/// <summary>
	/// Gets an item from the array
	/// </summary>
	/// <param name="index">The index of the desired item</param>
	/// <returns>The item found at the index or nullptr if the index was out of bounds</returns>
	T getItem(int index);

	/// <summary>
	/// Checks if the actor is in the array
	/// </summary>
	/// <param name="actor">A reference to the actor to use to check</param>
	/// <returns>False if the actor is not in the array</returns>
	bool contains(T actor);

	int getLength();

	T operator[](int index);
private:
	T* m_items;
	int m_length = 0;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Create a new array with a size one greater than our old array
	T* tempArray = new T[getLength() + 1];

	//Copy the values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	//Set the last value in the new array to be the actor we want to add
	tempArray[getLength()] = item;

	delete[] m_items;

	//Set old array to hold the values of the new array
	m_items = tempArray;
	m_length++;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check to see if the actor was null
	if (!item)
	{
		return false;
	}

	bool actorRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[m_length - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		if (item != m_items[i])
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			actorRemoved = true;
		}
	}
	//Set the old array to the new array
	if (actorRemoved)
	{
		m_items = newArray;
		m_length--;
	}
	//Return whether or not the removal was successful
	return actorRemoved;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(int index)
{
	//Check to see if the actor was null
	if (index < 0 || index > m_length)
		return false;

	bool actorRemoved = false;
	//Create a new array with a size one less than our old array
	T* newArray = new T[m_length - 1];
	//Create variable to access tempArray index
	int j = 0;
	//Copy values from the old array to the new array
	for (int i = 0; i < m_length; i++)
	{
		if (index = i)
		{
			newArray[j] = m_items[i];
			j++;
		}
		else
		{
			actorRemoved = true;
		}
	}
	//Set the old array to the new array
	if (actorRemoved)
	{
		m_items = newArray;
		m_length--;
	}
	//Return whether or not the removal was successful
	return actorRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	int j = 0;
	T key;
	//Iterate through the array
	for (int i = 1; i < m_length; i++)
	{
		//Sets J to the previous index
		j = i - 1;

		//store the current value of the current index
		key = m_items[i];

		//While j is greater than the key and hasn't reached the end
		while (m_items[j] > key&& j >= 0)
		{
			//Moves the elements in the array up by 1
			m_items[j + 1] = m_items[j];
			j--;
		}

		//Set the index after j to be the key
		m_items[j + 1] = key;
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	if (index < 0 || index >= getLength())
		return T();
	return m_items[index];
}

template<typename T>
inline bool DynamicArray<T>::contains(T actor)
{
	//Iterate through actor array
	for (int i = 0; i < m_length; i++)
	{
		//return the current actor if it matches the argument
		if (m_items[i] == actor)
			return true;
	}

	return false;
}

template<typename T>
inline int DynamicArray<T>::getLength()
{
	return m_length;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= getLength())
		return m_items[index];
	throw std::exception("Index was outside the bounds of the Array");
}
