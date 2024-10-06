void MyQueue:: push(int x)
{
          QueueNode *temp=new QueueNode(x);
        if(front==NULL)
        {
            front=temp;
            rear=temp;
        }
        else
        {
         rear->next=temp;
         rear=temp;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        if(front==NULL)
        return -1;
        else
        {
            int res=front->data;
           QueueNode *temp=front->next;
            delete(front);
            front=temp;
            return res;
            
        }
}