#ifndef COMMUNICATORMANAGER_HPP
#define COMMUNICATORMANAGER_HPP

#include <QLinkedList>
#include "communicator.hpp"

class CommunicatorManager : protected QLinkedList<Communicator *>
{
	public:
		/// @fn CommunicatorManager();
		/// @brief Constructs an empty map
		CommunicatorManager();

		/// @fn void addCommunicator(Communicator * communicator);
		/// @brief Storing a communicator
		/// @param communicator Entity executing the low level network tasks
		void addCommunicator(Communicator * communicator);

		/// @fn void removeCommunicator(Communicator * communicator);
		/// @brief Removing a communicator from the manager
		/// @param communicator Communicator to remove
		void removeCommunicator(Communicator * communicator);
};

#endif // COMMUNICATORMANAGER_HPP
