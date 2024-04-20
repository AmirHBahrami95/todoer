#include "./libs.h"
#include "./Task.h"

#define help() (std::cout	<<"<a>dd\n<l>ist\n<e>dit ID\n<s>ave\n<i>mport PATH_TO_CSV\n<q>uit\n<h>elp\n---"<<std::endl)

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
				ts.push_back(std::move(todoer::read_task());
				std::cout<<"added."<<std::endl;
			break;

			case 'e':
				std::cout<<"[501 Not Implemented]"<<std::endl;
			break;

			case 's':
				
				// TODO write all the fuckers to some file with today's date
				std::cout<<"save to(."<<PSEP<<"temp.csv):"<<std::endl;
				std::getline(std::cin,move);
				if(move.empty())
					move=PSEP+"temp.csv";
				tasks_to_csv(move,ts);
				std::cout<<"saved to '"<<move<<"'"<<std::endl;
			break;

			case 'l':
				todoer::print_tasks(ts);
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

