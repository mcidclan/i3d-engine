#ifndef THREAD_HPP
#define THREAD_HPP

	#include <stdlib.h>

	class Thread
	{
		public:
			/// Constructor.
			Thread(void (*)(void));

			/// Destructor.
			~Thread();

			///
			static void* run(void*);

		private:
			///
			void (* runnable)(void);

	};

#endif
