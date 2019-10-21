#include "meeting_t.h"
#include "ad_t.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned int i = 1;
    ad_t calendar;

    while (i)
    {
        cout << "\nChoose option: \n"<< endl;
        cout << "0 - exit " << endl;
        cout << "1 - insert To AD" << endl;
        cout << "2 - remove From AD" << endl;
        cout << "3 - find In AD" << endl;
        cout << "4 - clean AD" << endl;
        cout << "5 - print AD" << endl;
        cout << "6 - save AD in file" << endl;
        
        cin >> i;
        switch (i)
        {
            case 0:
                i = 0;
                break;
            case 1:
            {
                bool answer = 0;
                float start = 0;
                float end = 0;
                string sub = "Lesson with Yosi\n";

                cout<<"enter start time: ";
                cin>>start;
                cout<<"enter end time: ";
                cin>>end;
                 /*cout<<"enter subject of meeting ";
                cin>>sub;*/
                
                try
                {
                    meeting_t* meet = new meeting_t(start, end, sub);
                    answer = calendar.insertAppointmentToAD(meet);
                }
                catch(int e)
                {
                    start = 0;
                    end = 0;
                    cout<<"can not create meeting - error: "<< e <<endl;
                    break;
                }   

                if(answer == true)
                {
                    cout<<"action completed successfully!"<<endl;
                }
                else
                {
                    cout<<"action failed"<<endl;
                }
            
                break;
            }
            case 2:
            {
                float startTime;
                meeting_t* removed;
                cout<< "Enter time of meeting to remove ";
                cin>>startTime;
                removed = calendar.removeAppointmentFromAD(startTime); // return poiter to remeved meeting
                if(removed == 0)
                {
                    cout<<"Nothing to remove!"<<endl;

                }
                else
                {
                    cout<<"Removed meeting: "<<endl;
                    removed->printMeeting();
                }
                break;
            }
            case 3:
            {
                float startTime;
                meeting_t* meetToFind;
                cout<< "Enter time of meeting to find ";
                cin>>startTime;
                meetToFind = calendar.findAppointmentInAD(startTime); // fin dAppointment In AD by hour
                cout<< "meeting found: "<<endl;
                if(meetToFind==0)
                {
                    cout<<"Not found!"<<endl;
                }
                else
                {
                    meetToFind->printMeeting();
                }
            
                break;
            }
            case 4:
            {
                calendar.cleanAD(); //clean AD

                break;
            }
            case 5:
            {
                calendar.printAD();
                
                break;
            }
            case 6:
            {
                cout<<"function in planning"<<endl;
                break;
            }
            
        }
    }

    return 0;
}

