🎓 Virtual Smart Campus System
A sleek, terminal-powered simulation of a modern university—bringing together students, professors, and campus life in one lightweight C++ application.

✨ Overview
Virtual Smart Campus System transforms your terminal into a vibrant, interactive campus.
Whether you’re a student eager to enroll in courses and borrow books, or a professor managing announcements and approvals, this app recreates the essential elements of university life—right from your command line.

Seamless authentication for students and professors

Modular design for easy navigation and future expansion

Persistent data via simple flat files—no database setup needed

Accessible everywhere with a clean, portable console interface

🚀 Features
🔐 Secure Login & Signup
Robust authentication for students and professors with persistent credential storage.

📘 Course Enrollment Workflow
Students request courses; professors approve or reject enrollments in real time.

📚 Library Management
Effortlessly browse, search, borrow, and return books—inventory tracked per title.

📢 Campus Announcements
Professors post important updates; students stay informed instantly.

🎒 Lost & Found Board
Report and discover lost or found items across the campus community.

.

🗂️ Project Structure
Virtual-Campus/
├── include/        # Header files
├── src/            # Source code
├── data/           # App state (flat files)
├── build/          # Compiled executable
└── README.md      

.
⚡ Quick Start
Prerequisite:
Make sure g++ is installed and available in your terminal.

Clone the repo:

text
git clone https://github.com/Adicode987/Virtual-Campus.git
cd Virtual-Campus
Create the build folder:

text
mkdir build
Compile the system:

text
g++ src/main.cpp src/Global.cpp src/Announcement.cpp src/LostAndFound.cpp -Iinclude -o build/app.exe
Prepare Data Files:
(Inside data/, create these empty files if missing)

announcements.txt

books.txt

borrowed.txt

courses.txt

credentials.txt

enrollments.txt

lost_and_found.txt

pending.txt

professors.txt

Run the application:

text
./build/app.exe
💻 Technologies Used
C++ (OOP, STL)

File I/O for lightweight data persistence

Modular header/source structure

Console UI for accessibility and portability

🌱 Future Enhancements
Attendance tracking

Grading and exam score management

Event/workshop management

Club and society memberships

🌟 Experience the future of campus life—right from your terminal! 🌟