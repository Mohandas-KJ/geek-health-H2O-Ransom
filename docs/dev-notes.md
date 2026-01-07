# Making One Dialogue close the other (TR - 1)
- we use a common event name `Global\\H2O_RANSOM_EXIT`
- Create the event in `hydrate.c` (Finished Parent's process)
- Opening the event in **Child process**
- Make the `MessageBox()` Threaded
- Start the Thread in the child process!
- Configure `waitHandles`
- If Dialog closed first -> Signal Exit
- Cleanup and Exit

## Observation:
- The Error Dialogs show, But, no Coordination. Trying to fix it!

## Fix 1:
- Pass the hExitEvent to the DisplayError Function
- Modify the Thread Args `struct` to get the Handle

## CONCLUSION TR - 1:  
**This Process is more complex a Dialog Box in Windows do not respond to handles, events or threads. So, it's very complex to co-ordinate them. This is unwanted in the developmental phase. It triggers the User to Drink Water.**

# Display Runtime at end (TR - 1):
- Get a `DWORD start` in Milliseconds `GetTickCount()`
- At the code end Get `end millisecs` 
- Convert them to `Seconds`
- Find `hour` from `seconds'
- Find `Minutes`
- Find `Seconds remaining`
- Print them neatly