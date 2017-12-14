#ifndef STORAGE_H
#define STORAGE_H

#include <forward_list.h>
#include <memory_pointer.h>

template<typename T> class Parameter {
    private:
        const String _name;
        uint16_t _address;
        T _value;

    public:
        Parameter(const String& name) : _name(name)
        {   
            _address = MemoryPointer::get();
            MemoryPointer::increment(sizeof(T));
            loadValue();

        }

        String name(){ return _name; }
        uint16_t address(){ return _address; }
        T value(){ return _value; }
        void setValue(T value){ _value = value; }
        void loadValue(){ EEPROM.get(_address, _value); }
        void storeValue(){ EEPROM.put(_address, _value); }
        void storeValue(T value){ setValue(value); storeValue(); }
};

template<typename T> class Storage {
    private:
        forward_list<Parameter<T>*> _parameters;

    public:
        Parameter<T>* add(const String name);
        void load();
        void store();

        bool get(const String name, Parameter<T>*& p);
        bool value(const String name, T& value);
        bool setValue(const String name, T value);
        bool storeValue(const String name);
        bool storeValue(const String name, T value);

        forward_iterator<Parameter<T>*> begin();
};

template<typename T> Parameter<T> *Storage<T>::add(const String name) {
    Parameter<T> *p = new Parameter<T>(name);
    _parameters.push_back(p);
    return p;
}

template<typename T> void Storage<T>::load() {
    forward_iterator<Parameter<T>*> i = _parameters.begin();
    while(i.has_next()) {
        i.next()->loadValue();
    }
}

template<typename T> void Storage<T>::store() {
    forward_iterator<Parameter<T>*> i = _parameters.begin();
    while(i.has_next()) {
        i.next()->storeValue();
    }
}

template<typename T> bool Storage<T>::get(const String name, Parameter<T>*& p) {
    forward_iterator<Parameter<T>*> i = _parameters.begin();
    while(i.has_next()) {
        p = i.next();
        if (name == p->name()) { return true; }
    }
    return false;
}

template<typename T> bool Storage<T>::value(const String name, T& value) {
    Parameter<T> *p;
    if (get(name, p)) {
        value = p->value();
        return true;
    }
    return false;
}

template<typename T> bool Storage<T>::setValue(const String name, T value) {
    Parameter<T> *p;
    if (get(name, p)) {
        p->setValue(value); 
        return true;
    }
    return false;
}

template<typename T> bool Storage<T>::storeValue(const String name) {
    Parameter<T> *p;
    if (get(name, p)) {
        p->storeValue();
        return true;
    }
    return false;
}

template<typename T> bool Storage<T>::storeValue(const String name, T value) {
    Parameter<T> *p;
    if (get(name, p)) {
        p->storeValue(value);
        return true;
    }
    return false;
}

template<typename T> forward_iterator<Parameter<T>*> Storage<T>::begin() {
    return _parameters.begin();
}

typedef Parameter<int32_t> Parami;
typedef Parameter<float> Paramf;
typedef Storage<int32_t> Storagei;
typedef Storage<float> Storagef;

#endif
