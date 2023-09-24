import React from "react";
import { Link, Outlet } from "react-router-dom";
import { Accordion } from "@material-tailwind/react";
import { ChevronRightIcon, ChevronLeftIcon } from "@heroicons/react/24/solid"

type Props = {
    open: boolean;
    dropDownOpen: boolean;
    setOpen(open: boolean): void;
    setDropDownOpen(dropDownOpen: boolean): void;
}

export default function SideBar({ open, setOpen, dropDownOpen, setDropDownOpen }: Props) {

    return (
        <>
            <div className="flex">
                <div className={`flex flex-col h-screen p-3 bg-white shadow max-[1024px]:hidden overflow-hidden transition-all ${open ? "w-64" : "w-10"}`}>

                    <div className="space-y-3">

                        <div className={`flex flex-row justify-between`}>

                            <div className={`flex items-center overflow-hidden transition-all ${open ? "w-full" : "w-0"}`}>
                                <h2 className={`font-bald text-xl`}>Dashboard</h2>
                            </div>

                            <button onClick={() => { setOpen(!open); }}>
                                {open ? <ChevronLeftIcon className="w-4 h-4" /> : <ChevronRightIcon className="w-4 h-4" />}
                            </button>

                        </div>

                        <div className={`flex-col transition-all overflow-hidden ${open ? "w-full" : "w-0"}`}>

                            <nav className="pt-2 pb-4 space-y-1 text-sm">
                                <Link to="/home" className="flex items-center p-2 space-x-3 rounded-md">Главная</Link>
                                <Link to="/news" className="flex items-center p-2 space-x-3 rounded-md">Новости</Link>

                                <div onMouseEnter={() => { setDropDownOpen(true); }}
                                    onMouseLeave={() => { setDropDownOpen(false); }}>

                                    <Link to="/about" className="flex items-center p-2 space-x-3 rounded-md">О компании</Link>

                                    <div className={`transition-all overflow-hidden duration-500 ease-in-out ${dropDownOpen ? "" : "hidden"} `}>
                                        <div className="flex flex-col m-2">
                                            <Link to="/history" className="items-center p-2 space-x-3 rounded-md">История</Link>
                                            <Link to="/services" className="items-center p-2 space-x-3 rounded-md">Услуги</Link>
                                            <Link to="/awards" className="items-center p-2 space-x-3 rounded-md">Награды</Link>
                                            <Link to="/reviews" className="items-center p-2 space-x-3 rounded-md">Отзывы</Link>
                                        </div>
                                    </div>

                                </div>

                                <Link to="/types" className="flex items-center p-2 space-x-3 rounded-md">Виды катеров/яхт</Link>
                                <Link to="/sales" className="flex items-center p-2 space-x-3 rounded-md">Продажа катеров/яхт</Link>
                                <Link to="/location" className="flex items-center p-2 space-x-3 rounded-md">Схема проезда</Link>
                                <Link to="/sitemap" className="flex items-center p-2 space-x-3 rounded-md">Карта сайта</Link>

                            </nav>

                        </div>
                    </div>
                </div>

                <div className="w-full h-full">
                    <Outlet />
                </div>
            </div>
        </>
    );

}
