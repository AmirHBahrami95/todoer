#include "./libs.h"
#include "./Task.h"

int main(){
	
	std::cout<< "-std=c++"<<__cplusplus/100<<std::endl;

	std::vector<todoer::Task> ts;
	std::string move;
	bool go_on=true;

	// setting output flags
	std::cout<<std::boolalpha;

	std::cout	<<"<a>dd <l>ist <e>dit <s>ave <q>uit <h>elp"<<std::endl;
	while(go_on){
		std::cout<<"$";
		std::getline(std::cin,move);
		switch(move[0]){
			case 'a':
				ts.push_back(std::move(todoer::read_task()));
				std::cout<<"added."<<std::endl;
			break;

			case 'e':
				std::cout<<"[501 Not Implemented]"<<std::endl;
			break;

			case 's':
				std::cout<<"[501 Not Implemented]"<<std::endl;
			break;

			case 'l':
				todoer::print_tasks(ts);
			break;

			case 'q':
				go_on=false;
			break;

			case 'h':
				std::cout	<<"<a>dd <l>ist <e>dit <q>uit <h>elp"<<std::endl;
			break;

			default:
				std::cout<<"[400 Bad Input]"<<std::endl;
			break;
		}

	}
	/**/

	// TODO write all the fuckers to some file with today's date

	return 0;
}

