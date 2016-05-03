#include "communicatormanager.hpp"

// Constructor
CommunicatorManager::CommunicatorManager() : QLinkedList<Communicator *>() {}

// Storing a communicator
void CommunicatorManager::addCommunicator(Communicator * communicator) {
	if (communicator != 0) {
		this->append(communicator);
	}
}

// Removing a communicator from the manager
void CommunicatorManager::removeCommunicator(Communicator * communicator) {
	if (communicator != 0) {
		this->removeAll(communicator);
		delete communicator;
	}
}
