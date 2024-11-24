# LabSolver

This class is created for easier creating console UI for my lab works<br>
includes single class "Solver" (yeap, bad name, but im too lazy to change it)<br>
includes 3 public and 1 private methods:
<ul>
	<li>void StartUp(bool _inf = true)</li>
	<li>void SelectTask()</li>
	<li>void ShowTasks()</li>
	<li>void ExecuteTask(int _index)</li>
</ul>

# Solver(const std::vector< Task >& _TaskList)
constructor<br>
one parameter - vector of Task structure<br><br>

Task - is struct. includes two fields:
<ul>
	<li><b>std::string name</b></li>
	<li><b>std::function<void()> func</b></li>
</ul>

<b>name</b> - is the name of task. you can leave it empty, so task will have name: "Task" + number_of_task (numeration from 1)<br>
<b>func</b> - is pointer to void function with no parameters. if you'll need to use parameters, use lambda function

# void StartUp(bool _inf = true)

lazy method for running console UI. after creating class you can already use this method.<br>
method have only one parameter: <b>_inf</b><br><br>

<b>_inf</b> - define if your ui will work infinitely. <b>TRUE</b> by default. when task is over Solver will ask you if you want to try again. if _inf = <b>FALSE</b> Solver won't ask you.

# void SelectTask()

this method is selecting task. also processes incorrect input

# void ShowTasks()

print all the task Solver have. if task don't have name print "Task" + number_of_task (numeration from 1)

# bool ExecuteTask(int _index)

Executes task. also processes incorrect number of task.<br>
if task is exist, return true and execute task.<br>
if task doesn't exist, return false and print error.
