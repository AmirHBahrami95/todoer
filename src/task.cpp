#ifndef TASK_H
	#include "./Task.h"
#endif

#include "./libs.h"
#include "./utils.h"

namespace todoer{

	void from_csv(std::vector<Task>& dest,std::string& path){
	
		// check if dest is full and if user gives 2 fucks about it
		std::string temp;
		if(!dest.empty()){
			std::cout<<"WARNING: if you read '"<<path<<"' you'll loose all current tasks (not written to any file). continue (n)? y/n";
			std::getline(std::cin,temp);
			if(temp[0]!='y')return;
			dest.clear();
		}

		std::ifstream fin{path};
		if(!fin){
			std::cerr<<"could not open '"<<path<<"'"<<std::endl;
			return;
		}
		
		std::string line;
		std::vector<std::string> temp_str;
		std::getline(fin,line); // skip headers // TODO make this thing settingable!
		while(std::getline(fin,line)){ // TODO escape VALSEP character, whatever it is
			temp_str=std::move(utils::split(line,','));
			dest.push_back(Task(temp_str[0],temp_str[1],temp_str[2]));
		}
		
	}

	Task read_task(){
		std::string temp[2];

		std::cout<<"task:";
		std::getline(std::cin,temp[0]);

		std::cout<<"description:";
		std::getline(std::cin,temp[1]);

		return {temp[0],temp[1]};
	};

	void print_tasks(std::vector<Task>& ts){
		std::cout<<std::endl<<ts[0].getHeaders()<<std::endl;
		for(int i=0;i<ts.size();i++){
			std::cout<<i<<",";
			ts[i].print();
		}
		std::cout<<std::endl;
	}

	void tasks_to_csv(std::ofstream& fout,std::vector<Task>& ts,bool write_headers){
		if(write_headers)
			fout<<ts[0].getHeaders()<<std::endl;
		for(int i=0;i<ts.size();i++)
			fout<<ts[i].to_string()<<'\n';
		fout.flush();
	}

	void tasks_to_csv(std::ofstream& fout,std::vector<Task>& ts){
		tasks_to_csv(fout,ts,true);	
	}

	void tasks_to_csv(std::string& path,std::vector<Task>& ts,bool write_headers){
		std::ofstream fout{path,std::ios::out};
		if(!fout){
			std::cerr<<"could not open '"<<path<<"' "<<std::endl;
			return ;
		}
		tasks_to_csv(fout,ts,write_headers);
	}

	void tasks_to_csv(std::string& path,std::vector<Task>& ts){
		tasks_to_csv(path,ts,true);
	}

};
