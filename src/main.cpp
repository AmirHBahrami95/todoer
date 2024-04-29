#include "./libs.h"
#include "./utils.h"
#include "./Directory.h"
#include "./Task.h"

#define help() (std::cout	<<"<a>dd |  <l>ist |  <e>dit ID |  <s>ave |  <i>mport PATH_TO_CSV |  <q>uit |  <h>elp\n---"<<std::endl)

// TODO 0 set  a settings.shit that sets the home directory
// TODO 1 make sure today's tasks are read each time user enters the program
// TODO 2 make sure the todo1 is writable in settings.shit
// TODO 3 introduce encryption :D
// TODO 4 make encryption done with gpg/ssl/... (without asking user for password)
// TODO 5 make a "CommandHandler" class and give it Directory and move jackshits. move the switch cases inside it

int main(){
	
	std::vector<todoer::Task> ts;
	
	std::string prog_home=USER_HOME;
	prog_home+=PSEP;
	prog_home+="todoer";

	#ifdef DEBUG
		// std::cout<<"prog_home:"<<prog_home<<std::endl;
	#endif

	utils::Directory d(prog_home);

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

			case 'c':
				std::cout<<"[501 Not Impleneted]"<<std::endl;
			break;

			case 's':
				if(ts.size()==0){
					std::cerr<<"nothing to save! you can <a>dd some tasks."<<std::endl;
					continue;
				}

				// TODO write all the fuckers to some file with today's date as default
				std::cout<<"save to (."<<PSEP<<"temp.csv):"<<std::endl;
				std::getline(std::cin,move);
				if(move.empty()){
					move=prog_home;
					move+=PSEP;
					move+="temp.csv"; // for some fucking reason
				}
				tasks_to_csv(move,ts);
				std::cout<<"saved to '"<<move<<"'"<<std::endl;
			break;

			case 'l':
				todoer::print_tasks(ts);
			break;

			case 'i':
				
				if(d.count_files(".csv")){
					std::cout<<d.get_path()<<std::endl;
					d.print_files(".csv");
				}

				std::cout<<"file: ";
				std::getline(std::cin,move);
				
				if(move.empty()) {
					std::cout<<"[400 Bad Request]"<<std::endl;
					continue;
				}

				if(std::isdigit(move[0]))
					move=d.full_path_of(move[0]-'0');

				if(move.empty()){
					std::cout<<"[404 Not Found]"<<std::endl;
					continue;
				}

				todoer::from_csv(ts,move);
				std::cout<<"imported '"<<move<<"' "<<std::endl;
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

