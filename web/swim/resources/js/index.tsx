import React from "react";
import ReactDOM from "react-dom/client";
import { BrowserRouter, RouterProvider } from "react-router-dom";
import router from "./routing/router";

ReactDOM.createRoot(document.getElementById('app') as Element).render(
    <React.StrictMode>
        <RouterProvider router={router} />
    </React.StrictMode>
)