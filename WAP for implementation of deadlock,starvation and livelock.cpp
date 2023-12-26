//9.WAP for implementation of deadlock,starvation and livelock.


//LIVELOCK :::::

var l1 = .... // lock object like semaphore or mutex etc
var l2 = .... // lock object like semaphore or mutex etc
	
		// Thread1
		Thread.Start( ()=&gt; {
			
	while (true) {
		
		if (!l1.Lock(1000)) {
			continue;
		}
		
		if (!l2.Lock(1000)) {
			continue;
		}
		
		/// do some work
	});

		// Thread2
		Thread.Start( ()=&gt; {
			
		while (true) {
			
			if (!l2.Lock(1000)) {
				continue;
			}
			
			if (!l1.Lock(1000)) {
				continue;
			}
			
			// do some work
		});


//DEADLOCK ::::::

var p = new object();
lock(p)
{
	lock(p)
	{
		// deadlock. Since p is previously locked
		// we will never reach here...
	}


//STARVATION ::::::

Queue q = .....

		while (q.Count & gt; 0)
{
	var c = q.Dequeue();
	.........

		// Some method in different thread accidentally
		// puts c back in queue twice within same time frame
		q.Enqueue(c);
	q.Enqueue(c);

	// leading to growth of queue twice then it
	// can consume, thus starving of computing
}
