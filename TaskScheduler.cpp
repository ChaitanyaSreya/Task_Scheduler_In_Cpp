#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, string> m;
int done=0, not_done=0;

void addNewTask(int priority, string task){ //This module helps the user to add his/ her activities along with priorities.
    m[priority]=task;
    cout<<"Added task: "<<task<<" with priority "<<priority<<endl;
	not_done++;
}

void showIncompleteTasks() {//This module displays all the activities which are not completed.
    
	auto it = m.begin();
	cout<<"No.\t\t\tTask\t\t\tPriority"<<endl;
	int i=1;
	while(it!=m.end()){
        cout<<i<<": \t\t\t"<<it->second<<"\t\t\t"<<it->first<<endl;
        it++; i++;
	}
}

void deleteTask(int priority) {
    /*This module works in the same way as markDone(). However, it is used to delete the activities which are not
      necessary and are to be deleted from the list.*/
	auto it = m.begin();
	while(priority!=1&&it!=m.end()){
	    cout<<priority<<endl;
	    priority--;
	    it++;
	    if(it==m.end()) --it;
	}
	if(priority==1)
	{
	    cout<<"Deleted task ";
	    cout<<it->second<<endl;
	    m.erase(it);
	    not_done--;
	    done++;
	}
}

void showUsage() { //This module guides the user on how to use the commands.
	cout<<"Usage :-"<<endl;
	cout<<"Type the following commands to add/delete tasks accordingly..\n\n\n"<<endl;
	cout<<"Add 1 Playing---->(This will add a new task with priority 1 and text \"Playing\" to the list)\n"<<endl;
    cout<<"Show----->(This will show incomplete priority tasks sorted by priority in ascending order)\n"<<endl;
	cout<<"DEL 1---->( This will delete the incomplete task with the given priority number)\n"<<endl;
	cout<<"DONE 1---->(This will mark the incomplete item with the given priority number as complete)\n"<<endl;
	cout<<"HELP----->(Shows how to use this application)\n"<<endl;
	cout<<"REPORT----->(Shows the statistics)\n"<<endl;
	cout<<"Exit---->(Exit from the application)\n"<<endl;
}

void statistics() {
    /*This module displays the statistics to the user about the count of activities which are completed and not completed.*/
	cout<<"TASKS_NOT_DONE = "<<not_done<<endl;
	cout<<"Completed = "<<done<<endl;
}

void markDone(int p) {
    /*This module marks the specified activity as done and deletes it from the list of activities.*/
	deleteTask(p);
}


int main(){
    
    cout<<endl;
    showUsage();
    while(1) {
        string task, text, option;
        int priority;
        
        cout<<"Enter any option ";
        cin>>option;
        if(option=="Add"){
            cin>>priority;
            getline(cin, text);
            addNewTask(priority, text);
        }
        else if(option=="Show"){
            showIncompleteTasks();
        }
        else if(option=="Del"){
            cin>>priority;
            deleteTask(priority);
        }
        else if(option=="DONE"){
            cin>>priority;
            markDone(priority);
        }
        else if(option=="HELP"){
            showUsage();
        }
        else if(option=="REPORT"){
            statistics();
        }
        else if(option=="Exit"){
            return 0;
        }
        else{
            cout<<"Error: Wrong syntax. Follow the instructions to continue: "<<endl;
            showUsage();
        }
    }
    return 0;
}
