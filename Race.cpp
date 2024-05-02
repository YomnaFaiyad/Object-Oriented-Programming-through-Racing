#include <iostream>
#include <iomanip>
using namespace std;

// Runner class
class Runner
{
  private:
    int num;
    string name;
    string represent;
    double event;
    double best_time;
    
  public:
    Runner() { }
    Runner (int n, string na, string rep, double ev, double bt)
    {
      num = n;
      name = na;
      represent = rep;
      event = ev;
      best_time = bt;
    }
    int getno(){return num;}
    string getname(){return name;}
    string getrepresent(){return represent;}
    double getevent(){return event;}
    double getbesttime(){return best_time;}
};

// Main function
int main() 
{
  // Declare variables
  int count, num;
  string name, represent;
  double events, best_time;
  double average = 0;
  int best_index = 0;

  // The number of runners that will be inputed
  cout << "Enter number of runners to input: ";
  cin >> count;

  // Declare an array of runner objects
  Runner runners[count];
  for (int i = 0; i < count; i++)
  {
    cout << endl << "Runner " << (i+1) << ": " << endl;
    cout << "Enter Runner Number: ";
    cin >> num; cin.ignore();
    cout << "Enter Runner Name: ";
    getline(cin, name);
    cout << "Enter Runner Represent: ";
    getline(cin, represent);
    cout << "Enter Runner Event: ";
    cin >> events;
    cout << "Enter Runner Best Time: ";
    cin >> best_time;

    // Store object 
    runners[i] = Runner(num, name, represent, events, best_time);
    // Calculate the average 
    average += best_time;
    // Calculate the best runner time
    if (best_time < runners[best_index].getbesttime())
      best_index = i;
  }
  average /= count;

  // Display the name of the best runner 
  cout << endl << "Best Runner: " << runners[best_index].getname();

  // Display the average time 
  cout << endl << "Average Time of Runners: " << fixed << setprecision(2) << average << endl;

return 0;
}

