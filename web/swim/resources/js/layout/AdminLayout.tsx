import React, { useState } from 'react'
import AdminSideBar from './AdminSideBar'

type Props = {}

export default function AdminLayout({ }: Props) {

    const [open, setOpen] = useState(true);

    return (
        <>
            <AdminSideBar
                open={open}
                setOpen={() => setOpen((cur) => !cur)}
            />
        </>
    )
}