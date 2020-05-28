#ifndef Queue_H
#define Queue_H
#include<exception>

class EmptyList : public std::exception {
public:
  virtual const char* what() const throw() {
    return "Lista vuota, impossibile effettuare l'operazione richiesta";
  }
};

class NotFound : public std::exception {
public:
  virtual const char* what() const throw() {
    return "L'oggetto non e' stato trovato\n";
  }
};

// Dichiarazione incompleta
template <typename T> class Queue;
// Dichiarazione incompleta
template <typename T> std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <typename T>
class Queue {
  friend class iterator;
  private:
    class Nodo;
    class SmartP {
      public:
        Nodo* punt;
        SmartP(Nodo* p = nullptr);
        SmartP(const SmartP&);
        ~SmartP();
        SmartP& operator=(const SmartP&);
        Nodo& operator*() const;
        Nodo* operator->() const;
        bool operator==(const SmartP&) const;
        bool operator!=(const SmartP&) const;
    };
    class Nodo {
      public:
        Nodo(const T& = T(), const SmartP& = nullptr, const SmartP& = nullptr);
        Nodo(const Nodo&);
        ~Nodo();
        T info;
        SmartP next, prec;
        int riferimenti;
    };
    SmartP first;
    SmartP last;
    static unsigned int _size;
  public:
    class iterator {
      friend class Queue<T>;
      private:
        SmartP iter;
      public:
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
        iterator& operator++();   // Prefisso
        iterator operator++(int); // Postfisso
        iterator& operator--();   // Prefisso
        iterator operator--(int); // Postfisso
        T& operator*() const;
    };
    // Costruttore
    Queue();
    // Operatori
    T& operator[](const iterator&) const;
    // Metodi
    unsigned int size() const;
    bool empty() const;
    iterator begin() const;
    iterator end() const;
    iterator pastTheEnd() const;
    iterator insert(const iterator&, const T&);
    iterator erase(const iterator&);
    iterator find(const T&) const;
    void clear();
    void push_back(const T&);
    void pop_back();
    void push_front(const T&);
    void pop_front();
    friend std::ostream& operator<< <T>(std::ostream&, const Queue<T>&);
};

/* Metodi si SmartP */

// Costruttore
template <typename T>
Queue<T>::SmartP::SmartP(Nodo* p) : punt(p) {
  if(punt) punt->riferimenti++;
}

// Costruttore di copia
template <typename T>
Queue<T>::SmartP::SmartP(const SmartP& s) : punt(s.punt) {
  if(punt) punt->riferimenti++;
}

// Distruttore
template <typename T>
Queue<T>::SmartP::~SmartP() {
  if(punt) {
    punt->riferimenti--;
    if(!punt->riferimenti) { delete punt; }
  }
}

// Oeratore di assegnazione
template <typename T>
typename Queue<T>::SmartP& Queue<T>::SmartP::operator=(const SmartP& s) {

  if(this != &s) {
    Nodo *t = punt;
    punt = s.punt;
    if(punt) punt->riferimenti++;
    if(t) {
      t->riferimenti--;
      if(!t->riferimenti) delete t;
    }
  }
  return *this;
}

// Operatore di dereferenziazione
template <typename T>
typename Queue<T>::Nodo& Queue<T>::SmartP::operator*() const { return *punt; }

// Operatore di selezione membro
template <typename T>
typename Queue<T>::Nodo* Queue<T>::SmartP::operator->() const { return punt; }

// Operatore di uguaglianza
template <typename T>
bool Queue<T>::SmartP::operator==(const SmartP& s) const { return punt == s.punt; }

// Operatore di disuguaglianza
template <typename T>
bool Queue<T>::SmartP::operator!=(const SmartP& s) const { return punt != s.punt; }

/* Metodi di Nodo */

// Ccostruttore
template <typename T>
Queue<T>::Nodo::Nodo(const T& t, const SmartP& n, const SmartP& p) : info(t), next(n), prec(p), riferimenti(0) {
  ++_size;
}

template <typename T>
Queue<T>::Nodo::Nodo(const Nodo& n) : info(n.info), next(n.next), prec(n.prec), riferimenti(n.riferimenti) {}

// Distruttore
template <typename T>
Queue<T>::Nodo::~Nodo() { --_size; }

/* Metodi di iterator */

// Operatore di dereferenziazione
template <typename T>
T& Queue<T>::iterator::operator*() const { return iter->info; }

// Operatore di uguaglianza
template <typename T>
bool Queue<T>::iterator::operator==(const iterator& i) const { return iter == i.iter; }

// Operatore di disuguaglianza
template <typename T>
bool Queue<T>::iterator::operator!=(const iterator& i) const { return iter != i.iter; }

// Operatore di incremento prefisso
template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator++() {
  if(iter != 0) iter = iter->next;
  return *this;
}

// Operatore di incremento postfisso
template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator++(int) {
  iterator aux = *this;
  if(iter != 0) iter = iter->next;
  return aux;
}

// Operatore di decremento prefisso
template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator--() {
  if(iter != 0) iter = iter->prec;
  return *this;
}

// Operatore di decremento postfisso
template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator--(int) {
  iterator aux = *this;
  if(iter != 0) iter = iter->prec;
  return aux;
}

/* Metodi di Queue */

// Costruttore
template <typename T>
Queue<T>::Queue() : first(nullptr), last(nullptr) {}

// Dimensione della coda
template <typename T>
unsigned int Queue<T>::_size = 0;

// OPERATORI
template <typename T>
T& Queue<T>::operator[](const iterator& i) const { return (i.iter)->info; }

template <typename T>
unsigned int Queue<T>::size() const { return _size; }

template <typename T>
bool Queue<T>::empty() const { return _size == 0; }

template <typename T>
typename Queue<T>::iterator Queue<T>::begin() const {
  iterator aux;
  aux.iter = first;
  return aux;
}

template <typename T>
typename Queue<T>::iterator Queue<T>::end() const {
  iterator aux;
  aux.iter = last;
  return aux;
}

template <typename T>
typename Queue<T>::iterator Queue<T>::pastTheEnd() const {
  iterator aux;
  aux.iter = nullptr;
  return aux;
}

template <typename T>
typename Queue<T>::iterator Queue<T>::insert(const iterator& it, const T& item) {
  if(first == nullptr || it.iter == first) {
    push_front(item);
    return begin();
  } else if(it.iter == last) {
    push_back(item);
    return end();
  } else {
    try {
      SmartP q = first;
      iterator aux;
      while(q != nullptr && !(it.iter == q)) q = q->next;
      if(q == nullptr) throw NotFound();
      else q = new Nodo(item, q, q->prec);
      aux.iter = q;
      return aux;
    } catch(std::exception& e) {
      std::cout << e.what() << std::endl;
      return begin();
    }
  }
}

template <typename T>
typename Queue<T>::iterator Queue<T>::erase(const iterator& it) {
  try {
    if(empty()) throw EmptyList();
  } catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return end();
  }
  if(it.iter == first) {
    pop_front();
    return begin();
  } else if(it.iter == last) {
    pop_back();
    return end();
  } else {
    try {
      SmartP q = first;
      iterator aux;
      while(q != nullptr && !(it.iter == q)) q = q->next;
      if(q == nullptr) throw NotFound();
      else {
        (q->prec)->next = q->next;
        aux.iter = q->next;
        return aux;
      }
    } catch(std::exception& e) {
      std::cout << e.what() << std::endl;
      return end();
    }
  }
}

template <typename T>
typename Queue<T>::iterator Queue<T>::find(const T& key) const {
  iterator it;
  for(it = begin(); it != pastTheEnd() && !(*(it) == key); ++it) {}
  if(it == pastTheEnd()) return pastTheEnd();
  else return it;
}

template <typename T>
void Queue<T>::clear() {
  try {
    if(empty()) throw EmptyList();
    else {
      while(first != nullptr) pop_front();
    }
  } catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return;
  }
}

template <typename T>
void Queue<T>::push_back(const T& item) {
  if(last == nullptr) first = last = new Nodo(item);
  else {
    last->next = new Nodo(item, nullptr, last);
    last = last->next;
  }
}

template <typename T>
void Queue<T>::pop_back() {
  try {
    if(empty()) throw EmptyList();
    else {
      if(last->prec == nullptr) first = last = nullptr;
      else {
        (last->prec)->next = nullptr;
        last = last->prec;
      }
    }
  } catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return;
  }
}

template <typename T>
void Queue<T>::push_front(const T& item) {
  if(first == nullptr) first = last = new Nodo(item);
  else {
    first->prec = new Nodo(item, first);
    first = first->prec;
  }
}

template <typename T>
void Queue<T>::pop_front() {
  try {
    if(empty()) throw EmptyList();
    else {
      if(first->next == nullptr) first = last = nullptr;
      else {
        (first->next)->prec = nullptr;
        first = first->next;
      }
    }
  } catch(std::exception& e) {
    std::cout << e.what() << std::endl;
    return;
  }
}

std::ostream& operator<<(std::ostream& os, const Operazione& o) {
  return os << "Operazione numero " << o.x << " - Da eseguire il " << o.d << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& l) {
  if(!l.empty()) {
    os << l.size() << " elementi memorizzati:\n" << std::endl;
    int i = 1;
    for(typename Queue<T>::iterator it = l.begin(); it != l.pastTheEnd(); ++it) {
      os << i++ << ") " << l[it] << std::endl;
    }
  } else os << "Nessuna elemento memorizzato" << std::endl;
  return os;
}

#endif // Queue_H
