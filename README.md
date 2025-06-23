# 🎓 Virtual Smart Campus System

A **lightweight, terminal-based C++ application** that simulates a virtual university environment. It features secure login, course enrollment, a library management system, campus-wide announcements, and a Lost & Found board — all in a clean, modular C++ codebase.

---

## 🚀 Features

- 🔐 **Student & Professor Authentication**  
  Secure signup and login system with persistent credential storage.

- 📘 **Course Enrollment with Professor Approval**  
  Students request to join courses; professors approve or reject enrollment requests.

- 📚 **Library Management System**  
  Search, borrow, and return books with title-based inventory tracking.

- 📢 **Campus Announcement Board**  
  Professors can post updates; students can view all campus-wide announcements.

- 🎒 **Lost & Found Module**  
  Students can report and browse lost/found items with community visibility.

---

## 🧠 Technologies Used

- C++ (OOP + STL)
- File I/O for lightweight persistent storage
- Modular structure (`.h` / `.cpp`)
- Console UI (terminal-based, cross-platform)

---

## 🌱 Future Enhancements

- ✅ Attendance Tracking System
- ✅ Grading and Exam Score Management
- ✅ Event & Workshop Management
- ✅ Club & Society Membership Management

---

## 🗂️ Folder Structure

```bash
Virtual-Campus/
├── include/         # Header files
├── src/             # Source code files
├── data/            # Flat files storing app state
├── build/           # Compiled binary output
└── README.md        # Project information and instructions

```

---

## 🛠️ Setup Instructions

### 📦 Prerequisite

Ensure `g++` is installed and available in your terminal.

### ⚙️ Steps to Run

```bash
# Clone the repository
git clone https://github.com/Adicode987/Virtual-Campus.git
cd Virtual-Campus

# Create a build folder
mkdir build

# Compile the project
g++ src/main.cpp src/Global.cpp src/Announcement.cpp src/LostAndFound.cpp -Iinclude -o build/app.exe

# Run the app
./build/app.exe
```
