#ifndef TASK_H
#define TASK_H 1
#include "./libs.h"
#include "./utils.h"

namespace todoer{

	class Task{
		public:
			
			Task(){};
			
			Task(std::string p_title,std::string p_desc):
				m_title(p_title),
				m_desc(p_desc),
				m_done(false)
			{
				m_ctime=utils::get_currdate_str();
			}

			Task (Task&& t):
				m_title(std::move(t.m_title)),
				m_desc(std::move(t.m_desc)),
				m_ctime(std::move(t.m_ctime)),
				m_done(t.m_done) // copying doesn't hurt here really!
			{}

			std::string to_string()const{ // in csv
				std::string out{"\""};
				out+=m_title;
				out+="\",\"";
				out+=m_desc;
				out+="\",";
				out+=m_ctime;
				out+=",";
				out+=m_done;
				out+=";";
				return out;
			}

			void print()const{
				std::cout<<to_string()<<std::endl;
			}

			void setDone(bool p_done){
				m_done=p_done;
			}

			void setDescription(std::string p_desc){
				m_desc=p_desc;
			}
			void setTitle(std::string p_title){
				m_title=p_title;
			}

		private:
			std::string m_title{"NULL"};
			std::string m_desc{"NULL"};
			std::string m_ctime{"NULL"};
			bool m_done{false};
	};

	Task read_task(){
		std::string temp[2];

		std::cout<<"task:";
		std::getline(std::cin,temp[0]);

		std::cout<<"description:";
		std::getline(std::cin,temp[1]);

		return {temp[0],temp[1]};
	};

	void print_tasks(std::vector<Task>& ts){
		std::cout<<std::endl<<"title,description,date"<<std::endl;
		for(int i=0;i<ts.size();i++){
			std::cout<<i<<",";
			ts[i].print();
		}
		std::cout<<std::endl;
	};

}
#endif
