#ifndef DIRECTORY_H
#define DIRECTORY_1

#include "./libs.h"
#include "./utils.h"

namespace utils{
	
	struct FileEntry{ // to make use of std::string for printing
		unsigned long inode;
		std::string name;
		unsigned char type;
		unsigned short size;
	};
	void print_file_entry(const FileEntry& fe);

	// ----------------------------------------->
	
	// TODO add support for windows [insert puke_emoji]
	class Directory{

		public:

			// get the current one
			Directory(std::string p_path):
			m_path(p_path){
				init_files();
			}
	
			Directory(){
				char *buff=get_current_dir_name();
				m_path=buff;
				#ifdef DEBUG
					std::cout<<"wd:="<<buff<<std::endl;
				#endif
				init_files();
				delete buff; // no need for destructor
				buff=nullptr;
			}
			
			void print_files(std::string ext)const {
				for(int i=0;i<m_files.size();i++){
					if(m_files[i].name=="." || m_files[i].name=="..") continue;
					if(ext=="*") {
						std::cout<<"("<<i+1<<")";
						print_file_entry(m_files[i]);
					}
					else if(ext!="*" && utils::str_ends_with(m_files[i].name,ext) ){
						std::cout<<"("<<i<<")";
						print_file_entry(m_files[i]);
					}
				}
				std::cout<<std::endl;
			}

			std::string full_path_of(int index,std::string ext) const{
				std::string fp=m_path+PSEP;
				std::string curr;
				for(int i=0;i<m_files.size() && index>=0;i++)
					if(utils::str_ends_with(m_files[i].name,ext)){
						curr=m_files[i].name;
						index--;
					}
				fp+=curr;
				return fp;
			}


			std::string full_path_of(int index) const{
				return full_path_of(index,".csv");
			}
	
			void print_files() const{
				print_files("*");
			}

			int count_files() const{
				return m_files.size()-2;
			}

			int count_files(std::string ext) const{
				int c=0;
				for(int i=0;i<m_files.size();i++)
					if(utils::str_ends_with(m_files[i].name,ext))
						c++; // no pun intended :)
				return c;
			}
			
			// GETTER(s)
			std::string get_path()const{	return m_path;	}

		private:
			
			std::string m_path{""};
			std::vector<FileEntry> m_files;
			
			void init_files(){
				errno=0;
				DIR *d=opendir(m_path.c_str()); // NULL on failure >:(

				// mkdir:0 on success, -1 if gone to shit >:(
				if(!d && ENOENT==errno && mkdir(m_path.c_str(),0740)==-1){
					perror("utils::Directory.init_files()");
					std::cout<<std::endl;
				}

				else{
					#ifdef DEBUG
						// std::cout<<"directory exists"<<std::endl;
					#endif
					init_file_names(d);
				}

				free(d);
				d=nullptr;
			}

			void init_file_names(DIR *d){	
				dirent *dtemp;
				std::string stemp;
				while(dtemp=readdir(d)){
					stemp=dtemp->d_name;
					m_files.push_back(FileEntry{
						dtemp->d_ino,
						stemp,
						dtemp->d_type,
						dtemp->d_reclen
					});
				}

				delete dtemp; // even tho the docs say don't attempt to free it!
				dtemp=nullptr;
			}

	};

	void print_file_entry(const FileEntry& fe){
		#ifdef DEBUG
				std::cout <<fe.name<<" ("
									<<(((float)fe.size)/1000)<<"KB) "
									<<std::endl;
		#else
			std::cout <<fe.name<<std::endl;
		#endif
	}

};

#endif
