# -*- coding: utf-8 -*-
"""
    @author: 数模加油站
    @time  : 2025/7/14 11:24
    @file  : classes.py
"""
from functools import reduce
from abc import abstractmethod, ABC
import math


class Base(ABC):
    """
        可靠系统基类
    """

    def __init__(self, p: float | list[float], num: int, r: int | float = None):
        """
            p
        Parameters
        ----------
        p: float | list[float]
            故障率，若为单个数值，则表示所有元素故障率都相同
        num: int
            元素数量
        """
        self.p = p
        self.num = num
        self.r = r
        self.__check_type__()

    def __check_type__(self):
        self.__check_num()
        self.__check_r__()
        if isinstance(self.p, float):
            self.__check_p_float()
            self.p = [self.p] * self.num
        else:
            self.__check_p_list()

    def __check_p_float(self):
        if self.p < 0 or self.p > 1:
            raise ValueError("p must be between 0 and 1")

    def __check_p_list(self):
        if len(self.p) != self.num:
            raise ValueError("length of p must be equal to num")
        for i in self.p:
            if not isinstance(i, float):
                raise TypeError("The constituent of p must be float")
            if i < 0 or i > 1:
                raise ValueError("The constituent of p must be between 0 and 1")

    def __check_num(self):
        if self.num <= 0:
            raise ValueError("num must be greater than 0")

    def __check_r__(self):
        if isinstance(self.r, float):
            if self.r > 1 or self.r < 0:
                raise ValueError("r must be between 0 and 1")
        else:
            if self.r > self.num:
                raise IndexError("r must be less than num")
            self.r = math.ceil(self.num * self.r)

    @abstractmethod
    def compute(self):
        pass


class Series(Base):
    """
        串联系统，需要指定参数p故障率，和参数num元素数量
    """

    def __init__(self, p: float | list[float], num: int):
        if isinstance(p, list):
            super().__init__([1 - i for i in p], num)
        else:
            super().__init__(1 - p, num)

    def compute(self):
        return reduce(lambda x, y: x * y, self.p)


class Parallel(Base):
    """
        并联系统，需要指定参数p故障率，和参数num元素数量
    """

    def __init__(self, p: float | list[float], num: int):
        super().__init__(p, num)

    def compute(self):
        return 1 - reduce(lambda x, y: x * y, self.p)


class Vote(Base):
    """
        表决系统
    """

    def __init__(self, p: float | list[float], num: int, r: int | float = None):
        super().__init__(p, num, r)


    def compute(self):
        pass
