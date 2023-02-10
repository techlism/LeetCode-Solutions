​The approach is fine but you are using an auxialiary array for each level.
The way it can be optimized is using linked list property of inserting at head.
#create a pointer named rightpointer with null as default.
now point the front->next=rightpointer and front=rightpointer that's it.
