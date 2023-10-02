import React from "react";
import { createBrowserRouter } from "react-router-dom";
import Home from "../pages/Home";
import News from "../pages/News";
import About from "../pages/About";
import Sales from "../pages/Sales";
import NotFound from "../pages/NotFound";
import AwardsDashboard from "../pages/Dashboard/AwardsDashboard";
import HistoryDashboard from "../pages/Dashboard/HistoryDashboard";
import NewsDashboard from "../pages/Dashboard/NewsDashboard";
import Login from "../pages/Login";
import ProtectedRoutes from "./ProtectedRoutes";
import AdminRoutes from "./AdminRoutes";
import Register from "../pages/Register";
import AdminLogin from "../pages/Dashboard/AdminLogin";
import Place from "../pages/Place";

const router = createBrowserRouter([
    {
        path: '/',
        element: <ProtectedRoutes />,
        children: [
            {
                path: '/home',
                element: <Home />
            },
            {
                path: '/news',
                element: <News />
            },
            {
                path: '/about',
                element: <About />
            },

            {
                path: '/sales',
                element: <Sales />
            },

            {
                path: '/place',
                element: <Place />
            },

        ]
    },
    {
        path: '/login',
        element: <Login />
    },
    {
        path: '/register',
        element: <Register />
    },
    {
        path: '/admin/',
        element: <AdminRoutes />,
        children: [
            {
                path: '/admin/awards',
                element: <AwardsDashboard />
            },
            {
                path: '/admin/history',
                element: <HistoryDashboard />
            },
            {
                path: '/admin/news',
                element: <NewsDashboard />
            },

            {
                path: '/admin/login',
                element: <AdminLogin />
            },
        ]
    },

    {
        path: '/*',
        element: <NotFound />
    },

])

export default router;