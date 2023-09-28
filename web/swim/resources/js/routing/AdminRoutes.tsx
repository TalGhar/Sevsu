import React from "react";
import { Navigate } from "react-router-dom";
import { Outlet } from "react-router-dom";
import AdminLayout from "../layout/AdminLayout";

function AdminRoutes() {

    const isAdminLogged = 0;

    return isAdminLogged ? (
        <>
            <Navigate to={'/admin'} />
            <AdminLayout />
        </>
    ) : (
        <>
            <Navigate to={'/admin/register'} />
            <Outlet />
        </>
    )
}

export default AdminRoutes;