#include <iostream>
#include <jni.h>
#include <fstream>
#include <vector>
using namespace std;

ifstream f("zoodata.txt");
vector<char[7]> tracks(100);
vector<char[16]> names(100);
vector<char[16]> types(100);
vector<char[16]> subtypes(100);
vector<int> eggs(100);
vector<int> nurses(100);
int index = 0;

int main()
{
	//GenerateData();
	do
	{
		DisplayMenu();
		//gather user choice
		int userSelection;
		cin >> userSelection;
		if(userSelection == 1) LoadDataFromFile();
		else if(userSelection == 2) GenerateData();
		else if(userSelection == 3) DisplayAnimalData();
		else if(userSelection == 4) AddAnimal();
		else if(userSelection == 5) RemoveAnimal();
		else if(userSelection == 6) SaveDataToFile();
		else if(userSelection == 7)
		{
			cout << "goodbye! go feed the monkies or something" << endl;
			exit(1);
		}
		else
		{
			cout << "invalid input. please try again" << endl;
		}
	}while(true);

	return 1;
}

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal()
{
	//gather user choices
     cout << "track #:" << endl;
     cin >> tracks.at(index+1);
     cout << endl << "name:" << endl;
     cin >> names.at(index+1);
     cout << endl << "type:" << endl;
     cin >> types.at(index+1);
     cout << endl << "subtype:" << endl;
     cin >> subtypes.at(index+1);
     cout << endl << "eggs" << endl;
     cin >> eggs.at(index+1);
     cout << endl << "nurses:" << endl;
     cin >> nurses.at(index+1);
     cout << endl;
     index++;
}


void RemoveAnimal()
{
	//remove the animal at the index choice
     int choice;
     cout << "At which index is the animal?" << endl;
     cin >> choice;
     tracks.erase(tracks.begin()+choice);
     names.erase(names.begin()+choice);
     types.erase(types.begin()+choice);
     subtypes.erase(subtypes.begin()+choice);
     eggs.erase(eggs.begin()+choice);
     nurses.erase(nurses.begin()+choice);
     //decrement index
     index--;
     cout << "animal successfully deleted" << endl;
}

void LoadDataFromFile()
{

     while(!f.eof())
     {
    	 f.read(tracks.at(index),6);
    	 f.read(names.at(index),15);
    	 f.read(types.at(index),15);
    	 f.read(subtypes.at(index),15);
    	 f >> eggs.at(index);
    	 f >> nurses.at(index);
    	 index++;
     }
     cout << "load complete" << endl;
}

void SaveDataToFile()
{
     for(int k = 0; k < index; k++)
     {
    	 f << tracks.at(k) << names.at(k) << types.at(k) << subtypes.at(k) << eggs.at(k) << nurses.at(k) << "\n";
     }
     cout << "save successfully completed" << endl;
}

void DisplayAnimalData()
{
	cout << "========================================================================" << endl;
	cout << "|| track  name            type            subtype         eggs nurses ||" << endl;
	cout << "========================================================================" << endl;
	for(int j = 0; j < index; j++)
	{
		cout << "|| " << tracks.at(j) << " " << names.at(j) << types.at(j) << subtypes.at(j) << eggs.at(j) << "    " << nurses.at(j) << "      ||" << endl;
	}
	cout << "========================================================================" << endl;
}

void DisplayMenu()
{
    cout << "====================================" << endl;
    cout << "||  wildlife zoo computer system  ||" << endl;
    cout << "====================================" << endl;
    cout << "||    1. load animal data         ||" << endl;
    cout << "||    2. generate data            ||" << endl;
    cout << "||    3. display animal data      ||" << endl;
    cout << "||    4. add record               ||" << endl;
    cout << "||    5. delete record            ||" << endl;
    cout << "||    6. save animal data         ||" << endl;
    cout << "||    7. exit                     ||" << endl;
    cout << "====================================" << endl;
    cout << "||  enter user selection:         ||" << endl;
    cout << "====================================" << endl;

}
