import React from 'react'

type Props = {}

export default function ServicesComponent({ }: Props) {
    return (
        <section className="py-20">
            <div className="container mx-auto">
                <h2 className="text-4xl font-bold mb-8">Наши услуги</h2>
                <div className="flex flex-wrap -mx-4">
                    <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-gradient-to-br from-orange-100 from-30% to-emerald-200 rounded-lg shadow p-6 cursor-pointer" onClick={() => window.location.href = '/sales'}>
                            <h3 className="text-xl font-bold mb-2">Продажа морского транспорта</h3>
                            <p className="leading-relaxed">
                                Наша компания предлагает услуги по продаже морского транспорта. Мы предлагаем широкий выбор судов различных типов и размеров, включая яхты, катера, круизные лайнеры и танкеры. Наша команда экспертов поможет вам выбрать транспортное средство, которое наилучшим образом соответствует вашим потребностям и бюджету.
                            </p>
                        </div>
                    </div>
                    <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-gradient-to-b from-orange-100 from-30% to-emerald-200 rounded-lg shadow p-6 cursor-pointer" onClick={() => window.location.href = '/sales'}>
                            <h3 className="text-xl font-bold mb-2">Аренда морского транспорта</h3>
                            <p className="leading-relaxed">
                                Наша компания предлагает услуги по аренде морского транспорта. Мы предоставляем широкий выбор судов различных типов и размеров, включая яхты, катера, круизные лайнеры и танкеры. Мы гарантируем высокое качество обслуживания и безопасность наших клиентов.
                            </p>
                        </div>
                    </div>
                    <div className="w-full md:w-1/2 lg:w-1/3 px-4 mb-8">
                        <div className="bg-gradient-to-bl from-orange-100 from-30% to-emerald-200 rounded-lg shadow p-6 cursor-pointer" onClick={() => window.location.href = '/place'}>
                            <h3 className="text-xl font-bold mb-2">Разместите свой транспорт!</h3>
                            <p className="leading-relaxed">
                                Мы предоставляем удобный и надежный способ продать или арендовать ваше судно. Мы гарантируем высокое качество обслуживания и безопасность наших клиентов.
                            </p>
                        </div>
                    </div>
                </div>
            </div>
        </section>
    )
}