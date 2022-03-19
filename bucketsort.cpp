#include <iostream>
using namespace std;
template <class T>
class node{
    public:
    T data;
    node * next;
    node(){
        data=0;
        next=NULL;
    }
    node(T val){
        data=val;
        next=NULL;
    }
};

template<class U>
class bucket{
    public:
    node<U>*head;
};

template<class T>
class bucketlist{
    int no_of_bucket;
    bucket<T>*array_of_buckets;
    public:

    bucketlist(){
      //default no. of buckets is 10
      no_of_bucket=10;
      array_of_buckets=new bucket<T>[no_of_bucket];
      for(int i=0;i<no_of_bucket;i++){
          array_of_buckets[i].head=NULL;
      }
    }

    void add_element(T val,int max_e){
        // cout<<val;
        node<T> *newnode=new node<T>(val);
        node<T> *temp=new node<T>;
        int range=max_e/no_of_bucket;
        int idx=val/range;
        // cout<<idx;
        if(array_of_buckets[idx].head!=NULL){
            temp=array_of_buckets[idx].head;
            if(temp->data > newnode->data){
                newnode->next=array_of_buckets[idx].head;
                array_of_buckets[idx].head=newnode;
            }
            else{
                while(temp->next!=NULL){
                    if((temp->next)->data > newnode->data){
                        break;
                    }
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                
            }
        }
        else{
            array_of_buckets[idx].head=newnode;
        }   
        // cout<<"added :"<<temp->data<<endl; 
    }
    void display(){
        node<T> *temp=new node<T>;
        int j=0;
        for(int i=0;i<no_of_bucket;i++){
            temp=array_of_buckets[i].head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }
    void sorted_array(T arr[]){
        node<T> *temp=new node<T>;
        int j=0;
        for(int i=0;i<no_of_bucket;i++){
            temp=array_of_buckets[i].head;
            while(temp!=NULL){
                arr[j++]=temp->data;
                temp=temp->next;
            }
        }
    }
};


int main()
{
    bucketlist <double> bl;
    double arr[]={1,10.6,7.8,9.5,2};
    int max_e;
    cout<<"Enter maximum element to be inserted(in power of 10):";
    cin>>max_e;
    for(int i=0;i<5;i++)
        bl.add_element(arr[i],100);

    bl.sorted_array(arr);
    cout<<"Sorted array is:";
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}