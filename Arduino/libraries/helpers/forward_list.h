#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

template<class T> struct forward_list_node {
    T data;
    forward_list_node<T> *next;
};

template<typename T> class forward_iterator {
    private:
        forward_list_node<T> *_next;

    public:
        forward_iterator(forward_list_node<T> *next) : _next(next){}

        bool has_next();
        const T& next();
        const T& peek_next();
};

template<typename T> bool forward_iterator<T>::has_next() {
    return _next;
}

template<typename T> const T& forward_iterator<T>::next() {
    forward_list_node<T> *current = _next;
    _next = _next->next;
    return (current->data);
}

template<typename T> const T& forward_iterator<T>::peek_next() {
    return (_next->data);
}

template<typename T> class forward_list {
    private:
        forward_list_node<T> *_begin = NULL;
        forward_list_node<T> *_end = NULL;

    public:
        ~forward_list() {
            while(_begin != NULL)
                pop_front();
        }

        void push_front(T v);
        void push_back(T v);
        void pop_front();
        forward_iterator<T> begin();
        size_t size();

};

template<typename T> void forward_list<T>::push_front(T v) {
    forward_list_node<T> *n = new forward_list_node<T>;
    n->data = v;
    n->next = _begin;
    _begin = n;
    if(!_end) { _end = n; };
}

template<typename T> void forward_list<T>::push_back(T v) {
    forward_list_node<T> *n = new forward_list_node<T>;
    n->data = v;
    n->next = NULL;
    _end->next = n;
    _end = n;
    if(!_begin) { _begin = n; }
}

template<typename T> void forward_list<T>::pop_front() {
    if(_begin != NULL) {
        forward_list_node<T> *n = _begin;
        _begin = _begin->next;
        delete n;
    } else {
        _end = _begin;
    }
}

template<typename T> forward_iterator<T> forward_list<T>::begin() {
    return forward_iterator<T>(_begin);
}

template<typename T> size_t forward_list<T>::size() {
    forward_iterator<T> i = begin();
    
    size_t n = 0;
    while(i.has_next()) {
        n++;
        i.next();
    }
    return n;
}

#endif // FORWARD_LIST
