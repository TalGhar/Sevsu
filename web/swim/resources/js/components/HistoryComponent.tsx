import React from 'react'

type Props = {}

export default function HistoryComponent({ }: Props) {
    return (
        <section className="">
            <div className="container mx-auto py-16 px-4">
                <h2 className="text-3xl font-bold mb-8">История</h2>
                <div className="flex flex-col md:flex-row md:space-x-8 ">
                    <div className="md:w-1/2">
                        <p className="mb-4 bg-gradient-to-b from-orange-50 from-30% to-emerald-100 rounded-md p-4 shadow-md">
                            Однажды группа друзей, разделявших страсть к яхтингу и морю, решила создать компанию, которая позволила бы им поделиться своей любовью к яхтам с другими. Они начали с покупки нескольких яхт и предложения их в аренду тем, кто хотел испытать роскошь и приключения на открытом море. Со временем их флот расширился, и они расширили свои услуги, включив в продажу яхты, а также аренду.
                        </p>
                        <p className="mb-4 bg-gradient-to-b from-orange-50 from-30% to-emerald-100 rounded-md p-4 shadow-md">
                            Постепенно, с ростом их репутации, рос и их бизнес. Они начали привлекать клиентов со всего мира, и их яхты стали известны своим качеством и комфортом. Они также начали предлагать индивидуальные маршруты, позволяя клиентам исследовать некоторые из самых красивых и экзотических мест в мире.
                        </p>
                    </div>
                    <div className="md:w-1/2">
                        <p className="mb-4 bg-gradient-to-b from-orange-50 from-30% to-emerald-100 rounded-md p-4 shadow-md">
                            Сегодня компания является одним из ведущих поставщиков продажи и аренды яхт, с флотом некоторых из самых роскошных и хорошо оборудованных яхт в мире. Они продолжают предлагать индивидуальные маршруты и исключительный сервис, обеспечивая, чтобы каждый клиент имел незабываемый опыт на открытом море.
                        </p>
                    </div>
                </div>
            </div>
        </section>
    )
}