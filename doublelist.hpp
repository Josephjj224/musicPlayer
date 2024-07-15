#include <string>
#include <iostream>

using namespace std;

class Node { 
    public: 
        string title;
        string artist;
        string album;
        Node* next;
        Node* prev;
    
        Node(string title, string artist, string album) {
            this->title = title;
            this->artist = artist; 
            this->album = album;
            next = nullptr;
            prev = nullptr;
        }
};

class Playlist {
    private:
        Node* head;
        Node* tail;
        Node* current; 
        int length;
    
    public:
        Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}

        Playlist(string title, string artist, string album) {
            Node* newNode = new Node(title, artist, album);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
        ~Playlist() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->artist << "\n " << temp->album << "\n " << temp->title;
                temp = temp->next;
            }
            cout << temp->artist << "\n " << temp->album << "\n " << temp->title << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void addTrack(string title, string artist, string album) {
            Node* newNode = new Node(title, artist, album);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        
        Node* get()
        {
            current = head;
            return current; 
        }

        void reverse()
        {
            Node * current =  head;
            Node * temp = nullptr;
      
            while (current != nullptr)
            {
              temp = current->prev;
              current-> prev = current->next; 
              current -> next = temp; 
               current = current->prev;
            }
             temp = head;
            head = tail;
            tail = temp;
        }
};


