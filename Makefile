recur.so: recur.c
	python setup.py build_ext --inplace


test: recur.so
	python test_recur.py


clean:
	rm -rf *.o *.so __pycache__/ build/
