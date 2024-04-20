#ifndef TASK_H
#define TASK_H 1
#include "./libs.h"
#include "./utils.h"

namespace todoer{

	class Task{
		public:
			
			Task(){};
			

			Task(std::string& p_title,std::string& p_desc,std::string& p_date):
				m_title(p_title),
				m_desc(p_desc),
				m_ctime(p_date),
				m_done(false)
			{}
			
			// TODO re-use constructor (nested)
			Task(std::string& p_title,std::string& p_desc):
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
				// out+=";"; // removed for now making it easier to parse rows back
				return out;
			}

			void print()const{std::cout<<to_string()<<std::endl;}

			void setDone(bool p_done){m_done=p_done;}
			void setDescription(std::string& p_desc){m_desc=p_desc;}
			void setTitle(std::string& p_title){m_title=p_title;}
			
			// TODO make this dude static
			std::string getHeaders(){
				return "title,description,date";
			}

		private:
			std::string m_title{"NULL"};
			std::string m_desc{"NULL"};
			std::string m_ctime{"NULL"};
			bool m_done{false};
	};

}
#endif
