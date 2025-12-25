class MyLinkedList{
    private:
        struct Node{
            int val;
            Node *next;
            Node(int x) : val(x), next(nullptr){}
        };    

        Node *dummyHead;
        int size;

    public:
        MyLinkedList(){
            dummyHead = new Node(0);
            size = 0;
        }

        ~MyLinkedList(){
            Node *cur = dummyHead;
            while (cur){
                Node *tmp = cur;
                cur = cur->next;
                delete tmp;
            }
        }

        int get(int index){
            if (index < 0 || index >= size){
                return -1;
            }

            Node *cur = dummyHead->next;
            for (int i = 0; i < index; i++){
                cur = cur->next;
            }

            return cur->val;
        }

        void addAtIndex(int index, int val){
            if (index > size){
                return;
            }
            Node *node = new Node(val);

            Node *pre = dummyHead;
            for (int i = 0; i < index; i++){
                pre = pre->next;
            }
            node->next = pre->next;
            pre->next = node;

            size++;
        }

        void addAtHead(int val){
            addAtIndex(0, val);
        }

        void addAtTail(int val){
            addAtIndex(size, val);
        }

        void deleteAtIndex(int index){
            if (index < 0 || index >= size){
                return;
            }

            Node *pre = dummyHead;
            for (int i = 0; i < index; i++){
                pre = pre->next;
            }

            Node *tmp = pre->next;
            pre->next = pre->next->next;
            delete tmp;

            size--;
        }
};