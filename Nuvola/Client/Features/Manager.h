#ifndef NUVOLA_CLIENT_FEATURES_MANAGER
#define NUVOLA_CLIENT_FEATURES_MANAGER
#include <string>
#include <vector>
#include "ManagedItem.h"

template<class T> class Manager : public ManagedItem {
protected:
    std::vector<T*>* items;
public:
    //Constructor
    explicit Manager(std::string name) : ManagedItem(name) {
        items = new std::vector<T*>();
    }
    //Add item
    void addItem(T* item) {
        items->push_back(item);
    }
    //Remove item at index
    void removeItem(int item) {
        items->erase(items->begin() + item);
    }
    //Remove item via pointer
    void removeItem(T* item) {
        //For each item
        for (int i = 0; i < items->size(); i++) {
            //If item has the same pointer
            if (item == items->at(i)) {
                //Remove it
                removeItem(i);
                return;
            }
        }
    }
    //Get item at index
    T* getItem(int index) {
        return items->at(index);
    }
    T* getItem(std::string name) {
        //Loop through all items
        for (int i = 0; i < items->size(); i++) {
            //Get item at i
            ManagedItem * currentItem = items->at(i);
            //Check if the item has the name
            if (name == currentItem->getName()) {
                //If it does, return it
                return currentItem;
            }
        }
        //Nothing was found, so return nullptr
        return nullptr;
    }
    std::vector<T*>* getItems() {
        return this->items;
    }
    //It is a Manager, so make sure we set this to return true
    bool isManager() override {
        return true;
    }
};


#endif /* NUVOLA_CLIENT_FEATURES_MANAGER */
