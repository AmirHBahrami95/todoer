#include "./libs.h"
#include "./utils.h"
#include "./Task.h"

#define help() (std::cout	<<"<a>dd\n<l>ist\n<e>dit ID\n<s>ave\n<i>mport PATH_TO_CSV\n<q>uit\n<h>elp\n---"<<std::endl)

// TODO 0 set  a settings.shit that sets the home directory
// TODO 1 make sure today's tasks are read each time user enters the program
// TODO 2 make sure the todo1 is writable in settings.shit
// TODO 3 introduce encryption :D
// TODO 4 make encryption done with gpg/ssl/... (without asking user for password)

int main(){
	
	std::vector<todoer::Task> ts;

	std::string move;
	bool go_on=true;

	help();
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
				
				// TODO write all the fuckers to some file with today's date
				std::cout<<"save to (."<<PSEP<<"temp.csv):"<<std::endl;
				std::getline(std::cin,move);
				if(move.empty()){
					move=".";
					move=PSEP+"temp.csv";
				}
				tasks_to_csv(move,ts);
				std::cout<<"saved to '"<<move<<"'"<<std::endl;
			break;

			case 'l':
				todoer::print_tasks(ts);
			break;

			case 'i':
				// TODO list potential files
				// std::cout<<"csv files directory available:"<<PL_ENDL;
				// d.print_files();
				std::cout<<"file: ";
				if(move.empty())
					move=PSEP+"temp.csv";
				std::getline(std::cin,move);
				todoer::from_csv(ts,move);
			break;

			case 'q':
				go_on=false;
			break;

			case 'h':
				help();
			break;

			default:
				std::cout<<"[400 Bad Input]"<<std::endl;
			break;
		}

	}

	return 0;
}

