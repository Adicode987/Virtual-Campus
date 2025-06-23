📚 Virtual Smart Campus System
A lightweight terminal-based application simulating a university environment. It includes secure login for students and professors, a library management system, course enrollment workflows, campus-wide announcements, and a Lost & Found board—all in a modular C++ codebase.

🚀 Features
🔐 Student & Professor Authentication
Signup and login system with persistent credential storage.

📘 Course Enrollment with Professor Approval
Students request courses; professors approve or reject enrollment.

📚 Library Management
Browse, search, borrow, and return books—tracking inventory per title.

📢 Campus Announcement System
Professors post announcements; all students can view them.

🎒 Lost and Found
Students can report lost/found items and browse community reports.

🧱 Folder Structure
Virtual-Campus/
├── include/              # All header files
├── src/                  # All source code files
├── data/                 # Flat files storing app state
├── build/                # (Generated) compiled executable
└── README.md             # Project info and usage
📦 Setup Instructions
🛠️ Prerequisite: Make sure g++ is installed and available in your terminal.

Clone the repo:
git clone https://github.com/Adicode987/Virtual-Campus.git
cd Virtual-Campus
Create a build folder (if not already there):
mkdir build
Compile the system:
g++ src/main.cpp src/Global.cpp src/Announcement.cpp src/LostAndFound.cpp -Iinclude -o build/app.exe
Run the application:
.\build\app.exe
Make sure these data files exist inside the data/ folder (can be empty to start):
announcements.txt
books.txt
borrowed.txt
courses.txt
credentials.txt
enrollments.txt
lost_and_found.txt
pending.txt
professors.txt
You can populate books.txt and others with sample data if needed.

🧠 Technologies Used
C++ (Object-Oriented, STL)
File I/O for lightweight data persistence
Modular header/source structure
Console UI for accessibility and portability
💡 Future Enhancements
Attendance tracking
Grading and exam score management
Event/workshop management
Club and society memberships
