#ifndef THREAD_HPP
#define THREAD_HPP

	class Thread
	{
		public:
			///
			/// Constructor.
			///
			Thread(void* (*)(void*));

			///
			/// Destructor.
			///
			~Thread();
	};

#endif
