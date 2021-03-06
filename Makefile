PHILO_ONE = philo_one
PHILO_TWO = philo_two
PHILO_THREE = philo_three

CASES := $(PHILO_ONE) $(PHILO_TWO) $(PHILO_THREE)
SUBMAKE = make $@ -C $(case);

all:
	$(foreach case, $(CASES), $(SUBMAKE))

one:
	make -C $(PHILO_ONE)
	$(PHILO_ONE)/philo_one

two:
	make -C $(PHILO_TWO)
	$(PHILO_TWO)/philo_two

three:
	make -C $(PHILO_THREE)
	$(PHILO_TWO)/philo_three

re:	clean all

clean:
	$(foreach case, $(CASES), $(SUBMAKE))

fclean:
	$(foreach case, $(CASES), $(SUBMAKE))
