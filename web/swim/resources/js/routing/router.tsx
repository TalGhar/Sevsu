import React from "react";
import { createBrowserRouter } from "react-router-dom";
import Home from "../pages/Home";
import News from "../pages/News";
import About from "../pages/About";
import History from "../pages/History";
import Services from "../pages/Services";
import Awards from "../pages/Awards";
import Reviews from "../pages/Reviews";
import Types from "../pages/Types";
import Rent from "../pages/Rent";
import Sales from "../pages/Sales";
import Location from "../pages/Location";
import SiteMap from "../pages/SiteMap";
import NotFound from "../pages/NotFound";
import AwardsDashboard from "../pages/Dashboard/AwardsDashboard";
import HistoryDashboard from "../pages/Dashboard/HistoryDashboard";
import NewsDashboard from "../pages/Dashboard/NewsDashboard";
import RequestsDashboard from "../pages/Dashboard/RequestsDashboard";
import ReviewsDashboard from "../pages/Dashboard/ReviewsDashboard";
import ServicesDashboard from "../pages/Dashboard/ServicesDashboard";
import GuestLayout from "../layout/GuestLayout";
import AdminLayout from "../layout/AdminLayout";
import Login from "../pages/Login";

const router = createBrowserRouter([
    {
        path: '/',
        element: <GuestLayout />,
        children: [
            {
                path: '/',
                element: <Home />
            },
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
                path: '/history',
                element: <History />
            },
            {
                path: '/services',
                element: <Services />
            },
            {
                path: '/awards',
                element: <Awards />
            },
            {
                path: '/reviews',
                element: <Reviews />
            },
            {
                path: '/types',
                element: <Types />
            },
            {
                path: '/rent',
                element: <Rent />
            },
            {
                path: '/sales',
                element: <Sales />
            },
            {
                path: '/location',
                element: <Location />
            },
            {
                path: '/sitemap',
                element: <SiteMap />
            },
            {
                path: '/login',
                element: <Login />
            },
        ]
    },
    {
        path: '/admin',
        element: <AdminLayout />,
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
                path: '/admin/requests',
                element: <RequestsDashboard />
            },
            {
                path: '/admin/reviews',
                element: <ReviewsDashboard />
            },
            {
                path: '/admin/services',
                element: <ServicesDashboard />
            },
        ]
    },
    {
        path: '/*',
        element: <NotFound />
    },

])

export default router;